#include "../Public/CodeTypeFlashCall.h"


//begin namespace block
namespace AUTH
{

CodeTypeFlashCall::CodeTypeFlashCall()
{
	this->_ConstructorID = -70357982;
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
}
CodeTypeFlashCall::~CodeTypeFlashCall()
{

}
}//end namespace block
