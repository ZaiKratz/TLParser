#include "../Public/CreateChannel.h"


//begin namespace block
namespace CHANNELS
{

CreateChannel::CreateChannel()
{
	this->_ConstructorID = -192332417;
	this->_ContentRelated = true;
}

CreateChannel::CreateChannel(bool broadcast, bool megagroup, FString title, FString about)
{
	this->_ConstructorID = -192332417;
	this->_ContentRelated = true;
	this->broadcast = broadcast;
	this->megagroup = megagroup;
	this->title = title;
	this->about = about;
}
void CreateChannel::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(broadcast)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(megagroup)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->title);
	Writer.TGWriteString(this->about);
}


void CreateChannel::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
CreateChannel::~CreateChannel()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
