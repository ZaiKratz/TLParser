#include "../Public/ReplyInlineMarkup.h"


//begin namespace block
namespace COMMON
{

ReplyInlineMarkup::ReplyInlineMarkup()
{
	this->_ConstructorID = 1218642516;
}

ReplyInlineMarkup::ReplyInlineMarkup(TArray<COMMON::KeyboardButtonRow*>  rows)
{
	this->_ConstructorID = 1218642516;
	this->rows = rows;
}
void ReplyInlineMarkup::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->rows.Num());
	for(auto X : this->rows)
	{
	X->OnSend(Writer);
	}
}


void ReplyInlineMarkup::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24093 = Reader.ReadInt();
	for(int32 i = 0; i < Len24093; i++)
	{
	auto X = reinterpret_cast<COMMON::KeyboardButtonRow*>(Reader.TGReadObject());
	rows.Add(X);
	}
	this->_Responded = true;
}
ReplyInlineMarkup::~ReplyInlineMarkup()
{

}
}//end namespace block
