
#include <math.h>
#include <vector>
#include "_hypre_utilities.h"
#include "HYPRE_krylov.h"
#include "HYPRE.h"
#include "HYPRE_parcsr_ls.h"

int hypre_solve ();

class HypreSolver2D
{

private:

	int i;
	int myid, num_procs;
	int N, n;

	int ilower, iupper;
	int local_size, extra;
	int num_iterations;
	double final_res_norm;

	double h, h2;

	HYPRE_IJMatrix A;
	HYPRE_ParCSRMatrix parcsr_A;
	HYPRE_IJVector hv_b;
	HYPRE_ParVector par_b;
	HYPRE_IJVector hv_x;
	HYPRE_ParVector par_x;

	HYPRE_Solver solver, precond;

	std::vector<double> rhs_values, x_values;
	std::vector<int> rows;

	void set_rhs(double *rhs);	

	void build_A();	

public:

	HypreSolver2D();

	void set_x0(double *x0);
	
	void build_solver();

	void solve(double *x);

	int get_num_iterations();

	double get_final_res_norm();

	int get_local_size();

	~HypreSolver2D();

};
