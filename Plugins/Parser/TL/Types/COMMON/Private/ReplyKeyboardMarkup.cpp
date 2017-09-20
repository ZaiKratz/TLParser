#include "../Public/ReplyKeyboardMarkup.h"


//begin namespace block
namespace COMMON
{

ReplyKeyboardMarkup::ReplyKeyboardMarkup()
{
	this->_ConstructorID = -1938488779;
}

ReplyKeyboardMarkup::ReplyKeyboardMarkup(bool resize, bool single_use, bool selective, TArray<COMMON::KeyboardButtonRow*> rows)
{
	this->_ConstructorID = -1938488779;
	this->resize = resize;
	this->single_use = single_use;
	this->selective = selective;
	this->rows = rows;
}
void ReplyKeyboardMarkup::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!resize)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(!single_use)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	if(!selective)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->rows.Num());
	for(auto X : this->rows)
	{
	X->OnSend(Writer);
	}
}


void ReplyKeyboardMarkup::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		resize = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		single_use = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		selective = true;
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len25065 = Reader.ReadInt();
	for(int32 i = 0; i < Len25065; i++)
	{
	auto X = reinterpret_cast<COMMON::KeyboardButtonRow*>(Reader.TGReadObject());
	rows.Add(X);
	}
}
ReplyKeyboardMarkup::~ReplyKeyboardMarkup()
{

}
}//end namespace block
