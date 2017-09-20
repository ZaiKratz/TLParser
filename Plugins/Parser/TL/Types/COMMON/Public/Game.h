#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/Photo.h"
#include "../../../Types/Common/Public/Document.h"

//begin namespace block
namespace COMMON
{
class Game : public TLBaseObject
{
public:
	Game();
	Game(unsigned long long id, unsigned long long access_hash, FString short_name, FString title, FString description, COMMON::Photo* photo, COMMON::Document* document);

	~Game();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 unsigned long long access_hash;
	 FString short_name;
	 FString title;
	 FString description;
	 COMMON::Photo* photo;
	 COMMON::Document* document;
};
} //end namespace block
