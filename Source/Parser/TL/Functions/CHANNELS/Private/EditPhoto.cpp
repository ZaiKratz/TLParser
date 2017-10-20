#include "../Public/EditPhoto.h"


//begin namespace block
namespace CHANNELS
{

EditPhoto::EditPhoto()
{
	this->_ConstructorID = -248621111;
	this->_ContentRelated = true;
}

EditPhoto::EditPhoto(COMMON::InputChannel*  channel, COMMON::InputChatPhoto*  photo)
{
	this->_ConstructorID = -248621111;
	this->_ContentRelated = true;
	this->channel = channel;
	this->photo = photo;
}
void EditPhoto::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	this->photo->OnSend(Writer);
}


void EditPhoto::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditPhoto::~EditPhoto()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->photo)
	{
		delete this->photo;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
