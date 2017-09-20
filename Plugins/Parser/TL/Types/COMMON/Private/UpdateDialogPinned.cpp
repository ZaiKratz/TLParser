#include "../Public/UpdateDialogPinned.h"


//begin namespace block
namespace COMMON
{

UpdateDialogPinned::UpdateDialogPinned()
{
	this->_ConstructorID = -861793833;
}

UpdateDialogPinned::UpdateDialogPinned(bool pinned, PRIVATE::Peer* peer)
{
	this->_ConstructorID = -861793833;
	this->pinned = pinned;
	this->peer = peer;
}
void UpdateDialogPinned::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!pinned)
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


void UpdateDialogPinned::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		pinned = true;
	}
	peer = reinterpret_cast<PRIVATE::Peer*>(Reader.TGReadObject());
}
UpdateDialogPinned::~UpdateDialogPinned()
{

}
}//end namespace block
