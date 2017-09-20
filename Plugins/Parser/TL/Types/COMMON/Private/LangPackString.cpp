#include "../Public/LangPackString.h"


//begin namespace block
namespace COMMON
{

LangPackString::LangPackString()
{
	this->_ConstructorID = -159264310;
}

LangPackString::LangPackString(FString key, FString value)
{
	this->_ConstructorID = -159264310;
	this->key = key;
	this->value = value;
}
void LangPackString::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->key);
	Writer.TGWriteString(this->value);
}


void LangPackString::OnResponce(BinaryReader& Reader)
{
	key = Reader.TGReadString();
	value = Reader.TGReadString();
}
LangPackString::~LangPackString()
{

}
}//end namespace block
