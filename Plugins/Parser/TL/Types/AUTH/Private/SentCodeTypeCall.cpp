#include "../Public/SentCodeTypeCall.h"


//begin namespace block
namespace AUTH
{

SentCodeTypeCall::SentCodeTypeCall()
{
	this->_ConstructorID = 1398007207;
}

SentCodeTypeCall::SentCodeTypeCall(int32 length)
{
	this->_ConstructorID = 1398007207;
	this->length = length;
}
void SentCodeTypeCall::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->length);
}


void SentCodeTypeCall::OnResponce(BinaryReader& Reader)
{
	length = Reader.ReadInt();
	this->_Responded = true;
}
SentCodeTypeCall::~SentCodeTypeCall()
{

}
}//end namespace block
