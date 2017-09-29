#include "../Public/InputPeerNotifySettings.h"


//begin namespace block
namespace COMMON
{

InputPeerNotifySettings::InputPeerNotifySettings()
{
	this->_ConstructorID = 949182130;
}

InputPeerNotifySettings::InputPeerNotifySettings(bool show_previews, bool silent, int32 mute_until, FString sound)
{
	this->_ConstructorID = 949182130;
	this->show_previews = show_previews;
	this->silent = silent;
	this->mute_until = mute_until;
	this->sound = sound;
}
void InputPeerNotifySettings::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(show_previews)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	if(silent)
	{
		Flags |= (1 << 1);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	Writer.WriteInt(this->mute_until);
	Writer.TGWriteString(this->sound);
}


void InputPeerNotifySettings::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
		show_previews = true;
	}
	if((Flags & (1 << 1)) != 0) 
	{
		silent = true;
	}
	mute_until = Reader.ReadInt();
	sound = Reader.TGReadString();
	this->_Responded = true;
}
InputPeerNotifySettings::~InputPeerNotifySettings()
{

}
}//end namespace block
