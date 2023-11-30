#include "pch.h"
#include "../../Synapse/types.h"
#include "../../Synapse/Auto_associator.h"


TEST(TestCaseName, TestName)
{
	synp::AutoAssociator mem(3, signalType::BINARY);
	

	row_space pattern({ 1,0,1 }),
		pattern2({ 1,1,0 });
	pattern.print("INPUT");
	mem.memorize(pattern);
	mem.memorize(pattern2);
	mem.recall(row_space({ 1,0,1 })).print("Recall");

}