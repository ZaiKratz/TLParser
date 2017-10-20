#include "../Public/CodeTypeFlashCall.h"


//begin namespace block
namespace AUTH
{

CodeTypeFlashCall::CodeTypeFlashCall()
{
	this->_ConstructorID = 577556219;
}
void CodeTypeFlashCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void CodeTypeFlashCall::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
CodeTypeFlashCall::~CodeTypeFlashCall()
{
}
}//end namespace block
