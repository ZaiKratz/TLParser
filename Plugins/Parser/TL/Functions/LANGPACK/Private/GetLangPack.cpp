#include "../Public/GetLangPack.h"


//begin namespace block
namespace LANGPACK
{

GetLangPack::GetLangPack()
{
	this->_ConstructorID = -1899645542;
	this->_ContentRelated = true;
}

GetLangPack::GetLangPack(FString lang_code)
{
	this->_ConstructorID = -1899645542;
	this->_ContentRelated = true;
	this->lang_code = lang_code;
}
void GetLangPack::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->lang_code);
}


void GetLangPack::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::LangPackDifference*>(Reader.TGReadObject());
}
GetLangPack::~GetLangPack()
{

}
}//end namespace block
