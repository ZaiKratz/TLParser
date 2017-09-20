#include "../Public/ExportMessageLink.h"


//begin namespace block
namespace CHANNELS
{

ExportMessageLink::ExportMessageLink()
{
	this->_ConstructorID = 768755400;
	this->_ContentRelated = true;
}

ExportMessageLink::ExportMessageLink(COMMON::InputChannel* channel, int32 id)
{
	this->_ConstructorID = 768755400;
	this->_ContentRelated = true;
	this->channel = channel;
	this->id = id;
}
void ExportMessageLink::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteInt(this->id);
}


void ExportMessageLink::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::ExportedMessageLink*>(Reader.TGReadObject());
}
ExportMessageLink::~ExportMessageLink()
{

}
}//end namespace block
