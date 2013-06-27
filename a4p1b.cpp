#include <memory>
#include <iostream>

/**
  The number of distinct cycle structures in S_n.

  @param n
  @return the number of cycle structures in S_n.
 */
unsigned num_cycle_structures(unsigned n);

int main()
{
    std::cout << num_cycle_structures(10) << std::endl;
}

unsigned num_cycle_structures(unsigned N)
{
    auto dmatrix = std::unique_ptr<std::unique_ptr<unsigned[]>[]>{
        new std::unique_ptr<unsigned[]>[N+1]
    };

    for (int i=0; i<=N; ++i) {
        dmatrix[i].reset( new unsigned[N+1]{ 0 } );
    }

    for (int i=0; i<=N; ++i) {
        dmatrix[i][0] = dmatrix[0][i] = 1;
        dmatrix[i][1] = dmatrix[1][i] = 1;
    }

    for (int n=2; n<=N; ++n) {
        for (int x=2; x<=N; ++x) {
            int k = n<x? n : x;
            for (int i=1; i<=k; ++i) {
                dmatrix[n][x] += dmatrix[n-i][i];
            }
        }
    }

    return dmatrix[N][N];
}
