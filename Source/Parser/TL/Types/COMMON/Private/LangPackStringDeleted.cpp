#include "../Public/LangPackStringDeleted.h"


//begin namespace block
namespace COMMON
{

LangPackStringDeleted::LangPackStringDeleted()
{
	this->_ConstructorID = 695856818;
}

LangPackStringDeleted::LangPackStringDeleted(FString key)
{
	this->_ConstructorID = 695856818;
	this->key = key;
}
void LangPackStringDeleted::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->key);
}


void LangPackStringDeleted::OnResponce(BinaryReader& Reader)
{
	key = Reader.TGReadString();
	this->_Responded = true;
}
LangPackStringDeleted::~LangPackStringDeleted()
{

}
}//end namespace block
