
#include <random>
#include <vector>
#include <string>
#include "flann/flann.hpp"

using namespace std;
using namespace flann;


int main()
{
    unsigned int seed = 100;
    default_random_engine generator(seed);

    uniform_real_distribution<float> distribution(0.0f, 1.0f);



    int knn = 100;
    int cols = 100;
    int rows1 = 3000;
    int rows2 = 2000;
    int rows3 = 3000;


    int removeNum = 1000;
    int rows_query = 500;
    float *data1 = new float[rows1*cols];
    for (int i = 0; i != rows1*cols; ++i)
    {
        data1[i] = distribution(generator);
    }
    float *data2 = new float[rows2*cols];
    for (int i = 0; i != rows2*cols; ++i)
    {
        data2[i] = distribution(generator);
    }

    float *data3 = new float[rows3*cols];
    for (int i = 0; i != rows3*cols; ++i)
    {
        data3[i] = distribution(generator);
    }


    float *data_qury = new float[rows_query*cols];
    for (int i = 0; i != rows_query*cols; ++i)
    {
        data_qury[i] = distribution(generator);
    }


    Matrix<float>  dataset1(data1, rows1, cols);
    Matrix<float> dataset2(data2, rows2, cols);
    Matrix<float> dataset3(data3, rows3, cols);

    Matrix<float> query(data_qury, rows_query, cols);
    vector<vector<int>> indices;
    vector<vector<float>> dist;
    MultiThreadHierarchicalIndexParams params;
   // MultiThreadIndex<L2<float>> index(dataset1, params);
    MultiThreadIndex<L2<float>> index(params);

    //index.buildIndex();
    index.addPoints(dataset2);

    index.knnSearch(query, indices, dist, knn, SearchParams());


    //     index.removePoint(0);
    //     index.removePoint(100);
    for (int i = 0; i != removeNum; ++i)
    {
        index.removePoint(i);
    }

    index.knnSearch(query, indices, dist, knn, SearchParams());

    index.addPoints(dataset3);


    index.knnSearch(query, indices, dist, knn, SearchParams());

    delete[] data1;
    delete[] data2;
    delete[] data3;
    delete[] data_qury;

    return 0;
}