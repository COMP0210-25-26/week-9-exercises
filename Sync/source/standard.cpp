#include <mpi.h>

int main()
{
    MPI_Init(NULL, NULL);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int n_ranks;
    MPI_Comm_size(MPI_COMM_WORLD, &n_ranks);
    int neighbour_rank;

    MPI_Send(&rank, 1, MPI_INT, (rank+1)%n_ranks, 0, MPI_COMM_WORLD);

    MPI_Recv(&neighbour_rank, 1, MPI_INT, (rank-1)%n_ranks, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("My rank is %d and the neighbour is rank %d\n", rank, neighbour_rank);

    MPI_Finalize();

    return 0;
}