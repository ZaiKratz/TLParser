#include "../Public/UpdateFavedStickers.h"


//begin namespace block
namespace COMMON
{

UpdateFavedStickers::UpdateFavedStickers()
{
	this->_ConstructorID = -451831443;
}
void UpdateFavedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateFavedStickers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdateFavedStickers::~UpdateFavedStickers()
{
}
}//end namespace block
