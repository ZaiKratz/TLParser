#include "../Public/KeyboardButtonRow.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonRow::KeyboardButtonRow()
{
	this->_ConstructorID = 2002815875;
}

KeyboardButtonRow::KeyboardButtonRow(TArray<COMMON::KeyboardButton*>  buttons)
{
	this->_ConstructorID = 2002815875;
	this->buttons = buttons;
}
void KeyboardButtonRow::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->buttons.Num());
	for(auto X : this->buttons)
	{
	X->OnSend(Writer);
	}
}


void KeyboardButtonRow::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len8433 = Reader.ReadInt();
	for(int32 i = 0; i < Len8433; i++)
	{
	auto X = reinterpret_cast<COMMON::KeyboardButton*>(Reader.TGReadObject());
	buttons.Add(X);
	}
	this->_Responded = true;
}
KeyboardButtonRow::~KeyboardButtonRow()
{
}
}//end namespace block
