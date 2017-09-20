#include "../Public/UpdateReadFeaturedStickers.h"


//begin namespace block
namespace COMMON
{

UpdateReadFeaturedStickers::UpdateReadFeaturedStickers()
{
	this->_ConstructorID = 1109859671;
}
void UpdateReadFeaturedStickers::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdateReadFeaturedStickers::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UpdateReadFeaturedStickers::~UpdateReadFeaturedStickers()
{

}
}//end namespace block
