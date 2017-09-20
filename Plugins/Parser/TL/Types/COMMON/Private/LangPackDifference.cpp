#include "../Public/LangPackDifference.h"


//begin namespace block
namespace COMMON
{

LangPackDifference::LangPackDifference()
{
	this->_ConstructorID = -155089421;
}

LangPackDifference::LangPackDifference(FString lang_code, int32 from_version, int32 version, TArray<COMMON::LangPackString*> strings)
{
	this->_ConstructorID = -155089421;
	this->lang_code = lang_code;
	this->from_version = from_version;
	this->version = version;
	this->strings = strings;
}
void LangPackDifference::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->lang_code);
	Writer.WriteInt(this->from_version);
	Writer.WriteInt(this->version);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->strings.Num());
	for(auto X : this->strings)
	{
	X->OnSend(Writer);
	}
}


void LangPackDifference::OnResponce(BinaryReader& Reader)
{
	lang_code = Reader.TGReadString();
	from_version = Reader.ReadInt();
	version = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len3864 = Reader.ReadInt();
	for(int32 i = 0; i < Len3864; i++)
	{
	auto X = reinterpret_cast<COMMON::LangPackString*>(Reader.TGReadObject());
	strings.Add(X);
	}
}
LangPackDifference::~LangPackDifference()
{

}
}//end namespace block
