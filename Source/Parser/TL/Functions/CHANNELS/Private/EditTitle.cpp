#include "../Public/EditTitle.h"


//begin namespace block
namespace CHANNELS
{

EditTitle::EditTitle()
{
	this->_ConstructorID = 1450044624;
	this->_ContentRelated = true;
}

EditTitle::EditTitle(COMMON::InputChannel*  channel, FString title)
{
	this->_ConstructorID = 1450044624;
	this->_ContentRelated = true;
	this->channel = channel;
	this->title = title;
}
void EditTitle::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.TGWriteString(this->title);
}


void EditTitle::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
	this->_Responded = true;
}
EditTitle::~EditTitle()
{
	if(this->channel)
	{
		delete this->channel;
	}
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block
