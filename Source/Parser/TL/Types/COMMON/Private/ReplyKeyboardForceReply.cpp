#include "../Public/ReplyKeyboardForceReply.h"


//begin namespace block
namespace COMMON
{

ReplyKeyboardForceReply::ReplyKeyboardForceReply()
{
	this->_ConstructorID = -200242528;
}

ReplyKeyboardForceReply::ReplyKeyboardForceReply(bool single_use, bool selective)
{
	this->_ConstructorID = -200242528;
	this->single_use = single_use;
	this->selective = selective;
}
void ReplyKeyboardForceReply::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(single_use)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
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


void ReplyKeyboardForceReply::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		single_use = true;
	}
	if((Flags & (1 << 2)) != 0) 
	{
		selective = true;
	}
	this->_Responded = true;
}
ReplyKeyboardForceReply::~ReplyKeyboardForceReply()
{
}
}//end namespace block
