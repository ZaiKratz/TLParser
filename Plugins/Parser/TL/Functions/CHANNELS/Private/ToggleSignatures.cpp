#include "../Public/ToggleSignatures.h"


//begin namespace block
namespace CHANNELS
{

ToggleSignatures::ToggleSignatures()
{
	this->_ConstructorID = 112617759;
	this->_ContentRelated = true;
}

ToggleSignatures::ToggleSignatures(COMMON::InputChannel* channel, bool enabled)
{
	this->_ConstructorID = 112617759;
	this->_ContentRelated = true;
	this->channel = channel;
	this->enabled = enabled;
}
void ToggleSignatures::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->channel->OnSend(Writer);
	Writer.WriteBool(this->enabled);
}


void ToggleSignatures::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<COMMON::Updates*>(Reader.TGReadObject());
}
ToggleSignatures::~ToggleSignatures()
{

}
}//end namespace block
