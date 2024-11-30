#pragma once
#include "types.h"
#include "activators_mat.h"

/*

				__/\_____/\___
			   /              \  Mr.Owl
			  /  ___     ___   \
			  |  \_/     \_/   |
			  |	     ;f;       |
			   \\            //
			   / \ __---___ / \
			  / 			   \
			 //    \\\///      \\
			///    ///\\\      \\\
		   /////             \\\\\\
		  ////////////\\\\\\\\\\\\\\
		 ////////////  \\\\\\\\\\\\\\
		/////////\\\\??/////\\\\\\\\\\
	   ////////\\\\\\\////////\\\\\\\\\
	  ///////   \\\\\\///////  \\\\\\\\\
	 /////       \\\\\//////       \\\\\\
				  {}      {}
			 }{{}}}{}}  {}}{}{{}{


*/

namespace synp
{



	class AutoAssociator
	{
		Matf src_sig; //source signal
		Matf W; //weight matrix;
		signalType signalt;

	public:
		
		AutoAssociator(int sig_dims, signalType type);
		void memorize(row_space);
		row_space recall(row_space signal);
		void print()
		{
			this->W.print("Associator weights:");
			return;

		}
		Matf getWeight();

	



	};


	
}