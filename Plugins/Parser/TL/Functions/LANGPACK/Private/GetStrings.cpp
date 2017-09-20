#include "../Public/GetStrings.h"


//begin namespace block
namespace LANGPACK
{

GetStrings::GetStrings()
{
	this->_ConstructorID = 417537582;
	this->_ContentRelated = true;
}

GetStrings::GetStrings(FString lang_code, TArray<FString> keys)
{
	this->_ConstructorID = 417537582;
	this->_ContentRelated = true;
	this->lang_code = lang_code;
	this->keys = keys;
}
void GetStrings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->lang_code);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->keys.Num());
	for(auto X : this->keys)
	{
	Writer.TGWriteString(X);
	}
}


void GetStrings::OnResponce(BinaryReader& Reader)
{
}
GetStrings::~GetStrings()
{

}
}//end namespace block
