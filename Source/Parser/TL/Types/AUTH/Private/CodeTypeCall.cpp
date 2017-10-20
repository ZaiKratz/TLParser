#include "../Public/CodeTypeCall.h"


//begin namespace block
namespace AUTH
{

CodeTypeCall::CodeTypeCall()
{
	this->_ConstructorID = 1948046307;
}
void CodeTypeCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void CodeTypeCall::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
CodeTypeCall::~CodeTypeCall()
{
}
}//end namespace block
