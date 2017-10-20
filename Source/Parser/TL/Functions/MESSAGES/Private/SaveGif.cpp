#include "../Public/SaveGif.h"


//begin namespace block
namespace MESSAGES
{

SaveGif::SaveGif()
{
	this->_ConstructorID = 846868683;
	this->_ContentRelated = true;
}

SaveGif::SaveGif(COMMON::InputDocument*  id, bool unsave)
{
	this->_ConstructorID = 846868683;
	this->_ContentRelated = true;
	this->id = id;
	this->unsave = unsave;
}
void SaveGif::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
	Writer.WriteBool(this->unsave);
}


void SaveGif::OnResponce(BinaryReader& Reader)
{
		this->result = Reader.ReadBool();
	this->_Responded = true;
}
SaveGif::~SaveGif()
{
	if(this->id)
	{
		delete this->id;
	}
}
}//end namespace block
