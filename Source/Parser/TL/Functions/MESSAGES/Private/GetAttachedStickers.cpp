#include "../Public/GetAttachedStickers.h"


//begin namespace block
namespace MESSAGES
{

GetAttachedStickers::GetAttachedStickers()
{
	this->_ConstructorID = -866424884;
	this->_ContentRelated = true;
}

GetAttachedStickers::GetAttachedStickers(PRIVATE::InputStickeredMedia*  media)
{
	this->_ConstructorID = -866424884;
	this->_ContentRelated = true;
	this->media = media;
}
void GetAttachedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->media->OnSend(Writer);
}


void GetAttachedStickers::OnResponce(BinaryReader& Reader)
{
	this->_Responded = true;
}
GetAttachedStickers::~GetAttachedStickers()
{

}
}//end namespace block
