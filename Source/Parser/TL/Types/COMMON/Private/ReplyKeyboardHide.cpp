#include "../Public/ReplyKeyboardHide.h"


//begin namespace block
namespace COMMON
{

ReplyKeyboardHide::ReplyKeyboardHide()
{
	this->_ConstructorID = -1606526075;
}

ReplyKeyboardHide::ReplyKeyboardHide(bool selective)
{
	this->_ConstructorID = -1606526075;
	this->selective = selective;
}
void ReplyKeyboardHide::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(selective)
	{
		Flags |= (1 << 2);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void ReplyKeyboardHide::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 2)) != 0) 
	{
		selective = true;
	}
	this->_Responded = true;
}
ReplyKeyboardHide::~ReplyKeyboardHide()
{

}
}//end namespace block
