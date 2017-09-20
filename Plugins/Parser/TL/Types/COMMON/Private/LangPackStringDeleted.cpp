#include "../Public/LangPackStringDeleted.h"


//begin namespace block
namespace COMMON
{

LangPackStringDeleted::LangPackStringDeleted()
{
	this->_ConstructorID = -1292994263;
}

LangPackStringDeleted::LangPackStringDeleted(FString key)
{
	this->_ConstructorID = -1292994263;
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
}
LangPackStringDeleted::~LangPackStringDeleted()
{

}
}//end namespace block
