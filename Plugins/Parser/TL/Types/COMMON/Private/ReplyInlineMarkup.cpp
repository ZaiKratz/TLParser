#include "../Public/ReplyInlineMarkup.h"


//begin namespace block
namespace COMMON
{

ReplyInlineMarkup::ReplyInlineMarkup()
{
	this->_ConstructorID = 1409459016;
}

ReplyInlineMarkup::ReplyInlineMarkup(TArray<COMMON::KeyboardButtonRow*> rows)
{
	this->_ConstructorID = 1409459016;
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
	int32 Len23714 = Reader.ReadInt();
	for(int32 i = 0; i < Len23714; i++)
	{
	auto X = reinterpret_cast<COMMON::KeyboardButtonRow*>(Reader.TGReadObject());
	rows.Add(X);
	}
}
ReplyInlineMarkup::~ReplyInlineMarkup()
{

}
}//end namespace block
