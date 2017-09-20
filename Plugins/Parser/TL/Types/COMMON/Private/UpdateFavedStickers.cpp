#include "../Public/UpdateFavedStickers.h"


//begin namespace block
namespace COMMON
{

UpdateFavedStickers::UpdateFavedStickers()
{
	this->_ConstructorID = 1838748133;
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
}
UpdateFavedStickers::~UpdateFavedStickers()
{

}
}//end namespace block
