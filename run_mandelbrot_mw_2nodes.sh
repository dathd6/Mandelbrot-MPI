#!/bin/bash
# Number of nodes requied
#SBATCH --nodes=2
# Number of tasks per node
#SBATCH --ntasks-per-node=16
# Number of CPUs per task
#SBATCH --cpus-per-task=1
# Maximum time the job will run for (HH:MM:SS)
#SBATCH --time=6:00
# Name of the job
#SBATCH --job-name=Mandelbrot_v1
# Queue for the job to run in: training
#SBATCH -p training 
# Specify the account code and reservation
#SBATCH -A Research_Project-IscaTraining

# Unload all exisiting modules 
module purge
# Load the Intel Cluster Toolkit module used to compile the program
module load intel/2017b

# Run the program
mpirun ./mandelbrot_mpi_mw

# End of file
