#include "../Public/LangPackLanguage.h"


//begin namespace block
namespace COMMON
{

LangPackLanguage::LangPackLanguage()
{
	this->_ConstructorID = 292985073;
}

LangPackLanguage::LangPackLanguage(FString name, FString native_name, FString lang_code)
{
	this->_ConstructorID = 292985073;
	this->name = name;
	this->native_name = native_name;
	this->lang_code = lang_code;
}
void LangPackLanguage::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->name);
	Writer.TGWriteString(this->native_name);
	Writer.TGWriteString(this->lang_code);
}


void LangPackLanguage::OnResponce(BinaryReader& Reader)
{
	name = Reader.TGReadString();
	native_name = Reader.TGReadString();
	lang_code = Reader.TGReadString();
	this->_Responded = true;
}
LangPackLanguage::~LangPackLanguage()
{
}
}//end namespace block
