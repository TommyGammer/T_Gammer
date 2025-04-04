import os
import numpy as np
import matplotlib.pyplot as plt
from tensorflow import keras
from tensorflow.keras import layers, models, regularizers
from tensorflow.keras.datasets import cifar10
from tensorflow.keras.preprocessing.image import ImageDataGenerator
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# Load and preprocess the dataset
(x_train, y_train), (x_test, y_test) = cifar10.load_data()
x_train = x_train.astype("float32") / 255.0
x_test = x_test.astype("float32") / 255.0


model = keras.Sequential(
    [
        layers.Input(shape=(32,32,3)),

        #CNN
        layers.Conv2D(filters=32, kernel_size=(3, 3), activation='relu', padding='same',
                      kernel_regularizer=regularizers.l2(0.001)),
        layers.MaxPooling2D((2, 2)),

        layers.Conv2D(filters=64, kernel_size=(3, 3), activation='relu', padding='same',
                      kernel_regularizer=regularizers.l2(0.001)),
        layers.MaxPooling2D((2, 2)),

        layers.Conv2D(filters=128, kernel_size=(3, 3), activation='relu', padding='same',
                      kernel_regularizer=regularizers.l2(0.001)),
        layers.MaxPooling2D((2, 2)),

        layers.Conv2D(filters=128, kernel_size=(3, 3), activation='relu', padding='same',
                      kernel_regularizer=regularizers.l2(0.001)),
        layers.MaxPooling2D((2, 2)),

        layers.Conv2D(filters=64, kernel_size=(3, 3), activation='relu', padding='same',
                      kernel_regularizer=regularizers.l2(0.001)),
        layers.MaxPooling2D((2, 2)),

        # Dense
        layers.Flatten(),
        layers.Dense(512, activation='relu', kernel_regularizer=regularizers.l2(.001)),
        layers.BatchNormalization(),
        layers.Dropout(0.5),
        layers.Dense(256, activation='relu', kernel_regularizer=regularizers.l2(.001)),
        layers.BatchNormalization(),
        layers.Dropout(0.5),
        layers.Dense(128, activation='relu',kernel_regularizer=regularizers.l2(.001)),
        layers.BatchNormalization(),
        layers.Dense(10, activation='softmax')

    ]
)

model.summary()

# Compile the model
model.compile(
    loss=keras.losses.SparseCategoricalCrossentropy,
    optimizer=keras.optimizers.Adam(learning_rate=0.0003),
    metrics=["accuracy"],
)

# Gradually reduces the learning rate
reduce_lr = keras.callbacks.ReduceLROnPlateau(
    monitor='val_loss',
    factor=0.5,
    patience=5,
    min_lr=1e-7,
    verbose=1
)

# Changes images slightly to help decrease overfitting
datagen = ImageDataGenerator(
    rotation_range=15,
    width_shift_range=0.1,
    height_shift_range=0.1,
    horizontal_flip=True
)

datagen.fit(x_train)


# Train the model with learning rate schedule
history = model.fit(
    datagen.flow(x_train, y_train,batch_size=64),
    epochs=50,verbose=1,
    validation_data=(x_test, y_test),
    callbacks=[reduce_lr]
)

model.evaluate(x_test, y_test)


# Make predictions on the test set
y_pred = model.predict(x_test)
y_pred_classes = np.argmax(y_pred, axis=1)  # Convert predictions to class labels

# Function to change visualization names from numbers to associated objects
def predicted_type(num):
    testType = ""
    if num == 0:
        testType = "Airplane"
    elif num == 1:
        testType = "Automobile"
    elif num == 2:
        testType = "Bird"
    elif num == 3:
        testType = "Cat"
    elif num == 4:
        testType = "Deer"
    elif num == 5:
        testType = "Dog"
    elif num == 6:
        testType = "Frog"
    elif num == 7:
        testType = "Horse"
    elif num == 8:
        testType = "Ship"
    elif num == 9:
        testType = "Truck"
    return testType

# Function to visualize individual samples
def visualize_samples(indices):
    plt.figure(figsize=(12, 12))
    for i, idx in enumerate(indices):
        plt.subplot(5, 5, i + 1)
        plt.imshow(x_test[idx].reshape(32, 32, 3), cmap='gray')
        plt.title(f"True: {predicted_type(y_test[idx])}\nPred: {predicted_type(y_pred_classes[idx])}")
        plt.axis('off')
        if i >= 24:
            break
    plt.tight_layout()
    plt.show()

y_test_flat = y_test.flatten()

misclassified_indices = np.where(y_pred_classes != y_test_flat)[0]

# Number of samples to visualize
num_samples = min(25, len(np.where(y_pred_classes != y_test_flat)[0]))
sample_indices = np.random.choice(misclassified_indices, num_samples, replace=False)
visualize_samples(sample_indices)

# Final outputs and test set
#Epoch 50/50
#782/782 ━━━━━━━━━━━━━━━━━━━━ 31s 40ms/step - accuracy: 0.8453 - loss: 0.6424 - val_accuracy: 0.8208 - val_loss: 0.7347 - learning_rate: 1.5000e-04
#313/313 ━━━━━━━━━━━━━━━━━━━━ 2s 5ms/step - accuracy: 0.8234 - loss: 0.7322
