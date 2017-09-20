#include "../Public/Error.h"


//begin namespace block
namespace COMMON
{

Error::Error()
{
	this->_ConstructorID = -1141261884;
}

Error::Error(int32 code, FString text)
{
	this->_ConstructorID = -1141261884;
	this->code = code;
	this->text = text;
}
void Error::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->code);
	Writer.TGWriteString(this->text);
}


void Error::OnResponce(BinaryReader& Reader)
{
	code = Reader.ReadInt();
	text = Reader.TGReadString();
}
Error::~Error()
{

}
}//end namespace block
