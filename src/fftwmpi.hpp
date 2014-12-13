#include <fftw3.h>
#include <fftw3-mpi.h>
#include <mpi.h>
#include <cmath>
#include <iostream>
#include <vector>

void setup_fftw_mpi();

void cleanup_fftw_mpi();

class FFTWPoisson2DMPI
{

private:

	// fftw structures
	fftw_complex *out;
	double *in;
	fftw_plan p, pi;

	// Global problem dimensions
	ptrdiff_t N0, N1;
	ptrdiff_t local_n0, local_0_start, alloc_local;
	double Ly, Lx;

	// Local problem dimensions
	int nx, ny, nx_pad, y0;
	int nyc, nxc;

	// local k values
	std::vector<double> ky2_vals, kx2_vals;

public:

	FFTWPoisson2DMPI(ptrdiff_t N0, double Ly, ptrdiff_t N1, double Lx);

	void solve(double *x);

	int get_nx();
	int get_ny();
	int get_y0();

	~FFTWPoisson2DMPI();

};
