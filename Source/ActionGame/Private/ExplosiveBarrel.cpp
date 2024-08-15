// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AExplosiveBarrel::AExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Create the barrel mesh component
    BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("BarrelMesh");
    BarrelMesh->SetSimulatePhysics(true);
    RootComponent = BarrelMesh;

    // Create the radial force component
    RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
    RadialForceComp->SetupAttachment(RootComponent);
    RadialForceComp->Radius = 300.0f;
    RadialForceComp->bImpulseVelChange = true;
    RadialForceComp->bAutoActivate = false; 
    RadialForceComp->bIgnoreOwningActor = true;

    // Set the default explosion impulse
    ExplosionImpulse = 400.0f;

    // Bind the OnHit function to the mesh's OnComponentHit event
    BarrelMesh->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnHit);



}

// Called when the game starts or when spawned
void AExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

void AExplosiveBarrel::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Activate the radial force component to apply a force
    RadialForceComp->FireImpulse();

    // Apply an impulse to the barrel mesh
    FVector BoostIntensity = FVector::UpVector * ExplosionImpulse;
    BarrelMesh->AddImpulse(BoostIntensity, NAME_None, true);
}

// Called every frame
void AExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

