#include "../Public/UserProfilePhotoEmpty.h"


//begin namespace block
namespace COMMON
{

UserProfilePhotoEmpty::UserProfilePhotoEmpty()
{
	this->_ConstructorID = -507899569;
}
void UserProfilePhotoEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UserProfilePhotoEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
UserProfilePhotoEmpty::~UserProfilePhotoEmpty()
{

}
}//end namespace block
