#include "pch.h"
#include "../../Synapse/activators_mat.h"

#include "../../Synapse/types.h"
/// <summary>
/// this test will check for activation function giving right output
/// </summary>
TEST(float_32_256array, test_bipolar_activator)
{

	printf("\ntesting bipolar testing\n");
	 float arr[256];
	 for (int i = -(255/2), p = 0; i <= (255/2); i++, p++)
	 {
		 arr[p] = i;
	 }

	 Matf m(arr,1, 256);

	 Matf res=synp::bipolar(m);
	
	
	 for (int i = 0; i <= 255; i++)
	 {
		 if (i <(int)(255/2))//first half must be -1
			 ASSERT_EQ(res.at(0, i), -1)<<"bipolar activator not returning correct values";
		 else //other half must be +1
			 ASSERT_EQ(res.at(0, i), 1) << "bipolar activator not returning correct values";
	 }
	
}

TEST(float_32_256array, test_binary_activator)
{
	printf("\ntesting binary activator\n");
	
	float input_signal[256];
	for (int i = -127, p = 0; i <= 127; i++, p++)
	{
		input_signal[p] = i;
	}

	Matf m(input_signal, 1, 256);

	Matf response = synp::binary(m);

	
	for (int i = 0; i <= 255; i++)
	{
		if (i <127)//first half must be 0 cause negative
			ASSERT_EQ(response.at(0, i), 0) << ("binary activator not returning correct values fault at ");
		else //other half must be +1
			ASSERT_EQ(response.at(0, i), 1) << "binary activator not returning correct values";
	}


}