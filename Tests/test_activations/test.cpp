#include "pch.h"
#include "../../Synapse/activators_mat.h"

#include "../../Synapse/types.h"
/// <summary>
/// this test will check for activation function giving right output
/// </summary>
TEST(float_32_256array, test_bipolar_mat)
{

	
	 float arr[256];
	 for (int i = -127, p = 0; i <= 127; i++, p++)
	 {
		 arr[p] = i;
	 }

	 Matf m(arr,1, 256);

	 Matf res=synp::bipolar(m);
	
	
	 for (int i = 0; i < 255; i++)
	 {
		 if (i < 127)//first half must be -1
			 ASSERT_EQ(res.at(0, i), -1)<<"bipolar activator not returning correct values";
		 else //other half must be +1
			 ASSERT_EQ(res.at(0, i), 1) << "bipolar activator not returning correct values";
	 }
	
}