#include "../Public/KeyboardButtonSwitchInline.h"


//begin namespace block
namespace COMMON
{

KeyboardButtonSwitchInline::KeyboardButtonSwitchInline()
{
	this->_ConstructorID = 90744648;
}

KeyboardButtonSwitchInline::KeyboardButtonSwitchInline(bool same_peer, FString text, FString query)
{
	this->_ConstructorID = 90744648;
	this->same_peer = same_peer;
	this->text = text;
	this->query = query;
}
void KeyboardButtonSwitchInline::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(same_peer)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.TGWriteString(this->text);
	Writer.TGWriteString(this->query);
}


void KeyboardButtonSwitchInline::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		same_peer = true;
	}
	text = Reader.TGReadString();
	query = Reader.TGReadString();
	this->_Responded = true;
}
KeyboardButtonSwitchInline::~KeyboardButtonSwitchInline()
{
}
}//end namespace block
