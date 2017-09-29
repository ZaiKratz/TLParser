#include "../Public/SaveRecentSticker.h"


//begin namespace block
namespace MESSAGES
{

SaveRecentSticker::SaveRecentSticker()
{
	this->_ConstructorID = 958863608;
	this->_ContentRelated = true;
}

SaveRecentSticker::SaveRecentSticker(bool attached, COMMON::InputDocument*  id, bool unsave)
{
	this->_ConstructorID = 958863608;
	this->_ContentRelated = true;
	this->attached = attached;
	this->id = id;
	this->unsave = unsave;
}
void SaveRecentSticker::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(attached)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	this->id->OnSend(Writer);
	Writer.WriteBool(this->unsave);
}


void SaveRecentSticker::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveRecentSticker::~SaveRecentSticker()
{

}
}//end namespace block
