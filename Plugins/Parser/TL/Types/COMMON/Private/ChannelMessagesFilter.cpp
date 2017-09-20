#include "../Public/ChannelMessagesFilter.h"


//begin namespace block
namespace COMMON
{

ChannelMessagesFilter::ChannelMessagesFilter()
{
	this->_ConstructorID = 1473869773;
}

ChannelMessagesFilter::ChannelMessagesFilter(bool exclude_new_messages, TArray<COMMON::MessageRange*> ranges)
{
	this->_ConstructorID = 1473869773;
	this->exclude_new_messages = exclude_new_messages;
	this->ranges = ranges;
}
void ChannelMessagesFilter::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!exclude_new_messages)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->ranges.Num());
	for(auto X : this->ranges)
	{
	X->OnSend(Writer);
	}
}


void ChannelMessagesFilter::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 1)) != 0) 
	{
		exclude_new_messages = true;
	}
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len23162 = Reader.ReadInt();
	for(int32 i = 0; i < Len23162; i++)
	{
	auto X = reinterpret_cast<COMMON::MessageRange*>(Reader.TGReadObject());
	ranges.Add(X);
	}
}
ChannelMessagesFilter::~ChannelMessagesFilter()
{

}
}//end namespace block
