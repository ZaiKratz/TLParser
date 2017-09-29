#include "../Public/ToggleDialogPin.h"


//begin namespace block
namespace MESSAGES
{

ToggleDialogPin::ToggleDialogPin()
{
	this->_ConstructorID = 847887978;
	this->_ContentRelated = true;
}

ToggleDialogPin::ToggleDialogPin(bool pinned, PRIVATE::InputPeer*  peer)
{
	this->_ConstructorID = 847887978;
	this->_ContentRelated = true;
	this->pinned = pinned;
	this->peer = peer;
}
void ToggleDialogPin::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(pinned)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->peer->OnSend(Writer);
}


void ToggleDialogPin::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
ToggleDialogPin::~ToggleDialogPin()
{

}
}//end namespace block
