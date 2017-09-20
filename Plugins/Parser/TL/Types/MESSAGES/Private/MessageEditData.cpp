#include "../Public/MessageEditData.h"


//begin namespace block
namespace MESSAGES
{

MessageEditData::MessageEditData()
{
	this->_ConstructorID = -421677786;
}

MessageEditData::MessageEditData(bool caption)
{
	this->_ConstructorID = -421677786;
	this->caption = caption;
}
void MessageEditData::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!caption)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

}


void MessageEditData::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		caption = true;
	}
}
MessageEditData::~MessageEditData()
{

}
}//end namespace block
