#include "../Public/UpdateReadFeaturedStickers.h"


//begin namespace block
namespace COMMON
{

UpdateReadFeaturedStickers::UpdateReadFeaturedStickers()
{
	this->_ConstructorID = 1461528386;
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
	this->_Responded = true;
}
UpdateReadFeaturedStickers::~UpdateReadFeaturedStickers()
{

}
}//end namespace block
