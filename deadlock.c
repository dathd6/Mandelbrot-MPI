/* Example program which deadlocks. The bug is on line 26 where 0 should be 1.
 */
#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  int myRank;
  MPI_Status status;
  const int tag = 100;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

  /* Rank 0 sends a number rank 1 and receives a number from rank 1 */

  if (myRank == 0) {

    /* Send the number */
    float number_send = 3.141;
    printf("I am process %d sending %f\n", myRank, number_send);
    MPI_Send(&number_send, 1, MPI_FLOAT, 1, tag, MPI_COMM_WORLD);

    /* Receive a number */
    float number_recv;
    MPI_Recv(&number_recv, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);
    printf("I am process %d received %f\n", myRank, number_recv);

  } else if (myRank == 1) {

    /* Receive a number */
    float number_recv;
    MPI_Recv(&number_recv, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD, &status);
    printf("I am process %d received %f\n", myRank, number_recv);

    /* Send the number */
    float number_send = 1.234;
    printf("I am process %d sending %f\n", myRank, number_send);
    MPI_Send(&number_send, 1, MPI_FLOAT, 0, tag, MPI_COMM_WORLD);
  }

  MPI_Finalize();

  return 0;
}
