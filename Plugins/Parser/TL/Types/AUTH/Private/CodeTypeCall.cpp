#include "../Public/CodeTypeCall.h"


//begin namespace block
namespace AUTH
{

CodeTypeCall::CodeTypeCall()
{
	this->_ConstructorID = -472703884;
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
}
CodeTypeCall::~CodeTypeCall()
{

}
}//end namespace block
