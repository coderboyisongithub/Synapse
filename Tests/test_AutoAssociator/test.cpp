#include "pch.h"
#include "../../Synapse/types.h"
#include "../../Synapse/Auto_associator.h"




TEST(_3d_bipolar_signal, testAutoAssociative_bipolar_memorizeandrecall)
{
	
	synp::AutoAssociator mem(3, signalType::BIPOLAR);
	std::vector<row_space> signals;

	//create signals 3 bit bipolar
	signals.push_back({ -1,-1,-1 });
	signals.push_back({ -1,-1, 1 });
	signals.push_back({ -1, 1,-1 });
	signals.push_back({ -1, 1, 1 });
	signals.push_back({  1,-1,-1 });
	signals.push_back({  1,-1,-1 });
	signals.push_back({  1,-1, 1 });
	signals.push_back({  1, 1,-1 });
	signals.push_back({  1, 1, 1 });

	//memorize all signals
	for (int idx = 0; idx < 8; idx++)
		mem.memorize(signals[idx]);
	
	//recall 
	for (int idx = 0; idx < 8; idx++)
	{
		row_space recall=mem.recall(signals[idx]);
		row_space diff = recall - signals[idx];
		
		EXPECT_FLOAT_EQ(diff.at(0), 0)<< "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(1), 0)<< "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(2), 0)<< "network failled to recall ";
	}


	

}

TEST(_2d_bipolar_signal, testAutoAssociative_bipolar_memorizeandrecall)
{

	synp::AutoAssociator mem(2, signalType::BIPOLAR);
	std::vector<row_space> signals;

	//create signals 3 bit bipolar
	signals.push_back({ -1,-1 });
	signals.push_back({ -1, 1 });
	signals.push_back({  1,-1 });
	signals.push_back({  1, 1 });

	//memorize all signals
	for (int idx = 0; idx < 4; idx++)
		mem.memorize(signals[idx]);

	//recall 
	for (int idx = 0; idx < 4; idx++)
	{
		row_space recall = mem.recall(signals[idx]);
		row_space diff = recall - signals[idx];

		EXPECT_FLOAT_EQ(diff.at(0), 0) << "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(1), 0) << "network failled to recall ";
	}




}

TEST(_4d_bipolar_signal, testAutoAssociative_bipolar_memorizeandrecall)
{

	synp::AutoAssociator mem(4, signalType::BIPOLAR);
	std::vector<row_space> signals;

	//create signals 3 bit bipolar
	signals.push_back({ -1,-1,-1,-1 });
	signals.push_back({ -1,-1,-1, 1 });
	signals.push_back({ -1,-1, 1,-1 });
	signals.push_back({ -1,-1, 1, 1 });
	signals.push_back({ -1, 1,-1,-1 });
	signals.push_back({ -1, 1,-1, 1 });
	signals.push_back({ -1, 1, 1,-1 });
	signals.push_back({ -1, 1, 1, 1 });

	signals.push_back({  1,-1,-1,-1 });
	signals.push_back({  1,-1,-1, 1 });
	signals.push_back({  1,-1, 1,-1 });
	signals.push_back({  1,-1, 1, 1 });
	signals.push_back({  1, 1,-1,-1 });
	signals.push_back({  1, 1,-1, 1 });
	signals.push_back({  1, 1, 1,-1 });
	signals.push_back({  1, 1, 1, 1 });
	//memorize all signals
	for (int idx = 0; idx < 4; idx++)
		mem.memorize(signals[idx]);

	//recall 
	for (int idx = 0; idx < 4; idx++)
	{
		row_space recall = mem.recall(signals[idx]);
		row_space diff = recall - signals[idx];

		EXPECT_FLOAT_EQ(diff.at(0), 0) << "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(1), 0) << "network failled to recall ";
	}




}

TEST(_4d_random_signal_orthogonal, testAutoAssociative_bipolar_memorizeandrecall)
{

	synp::AutoAssociator mem(4, signalType::BIPOLAR);
	std::vector<row_space> signals;

	signals.push_back({ 1, 1,-1,-1 });
	signals.push_back({ -1,1,1,-1 });
	signals.push_back({ -1,1,-1,1 });
	signals.push_back({ 1,1,1,1 });
	//memorize all signals
	for (int idx = 0; idx < 4; idx++)
		mem.memorize(signals[idx]);

	//recall 
	for (int idx = 0; idx < 4 ;idx++)
	{
		row_space recall = mem.recall(signals[idx]);
		row_space diff = recall - signals[idx];

		EXPECT_FLOAT_EQ(diff.at(0), 0) << "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(1), 0) << "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(2), 0) << "network failled to recall ";
		EXPECT_FLOAT_EQ(diff.at(3), 0) << "network failled to recall ";
	}




}


