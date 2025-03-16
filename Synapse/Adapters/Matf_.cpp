#include "Matf_.h"

Matf::Matf()
{
	impl = new Eigenadapter;
}

void Matf::t()
{
	impl->t();
	return;
}
