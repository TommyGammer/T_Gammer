import os
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers, models
from tensorflow.keras.datasets import mnist
from PIL import Image
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

# Load and preprocess the dataset
(x_train, y_train), (x_test, y_test) = mnist.load_data()
x_train = x_train.reshape(-1, 784).astype("float32") / 255.0
x_test = x_test.reshape(-1, 784).astype("float32") / 255.0

# Build the model
model = keras.Sequential(
    [
        layers.Dense(512, activation='relu'),
        layers.Dense(256, activation='relu'),
        layers.Dense(10),
    ]
)

# Compile the model
model.compile(
    loss=keras.losses.SparseCategoricalCrossentropy(from_logits=True),
    optimizer=keras.optimizers.Adam(learning_rate=0.001),
    metrics=["accuracy"],
)

# Train the model
history = model.fit(x_train, y_train, batch_size=32, epochs=5, verbose=2, validation_data=(x_test, y_test))

# Make predictions on the test set
y_pred = model.predict(x_test)
y_pred_classes = np.argmax(y_pred, axis=1)

# Function to visualize individual samples
def visualize_samples(indices):
    plt.figure(figsize=(12, 12))
    for i, idx in enumerate(indices):
        plt.subplot(5, 5, i + 1)
        plt.imshow(x_test[idx].reshape(28, 28), cmap='gray')
        plt.title(f"True: {y_test[idx]}\nPred: {y_pred_classes[idx]}")
        plt.axis('off')
        if i >= 24:
            break
    plt.tight_layout()
    plt.show()

# Number of samples to visualize
num_samples = min(25, len(np.where(y_pred_classes != y_test)[0]))
misclassified_indices = np.where(y_pred_classes != y_test)[0]
sample_indices = np.random.choice(misclassified_indices, num_samples, replace=False)
visualize_samples(sample_indices)

# Load and preprocess personal image
def load_and_preprocess_image(image_path):
    img = Image.open(image_path).convert('L')
    img = img.resize((28, 28))
    img_array = np.array(img).astype("float32") / 255.0
    img_array = img_array.reshape(1, 784)
    return img_array

# Personal image I drew in photoshop for testing
image_path = 'Small_Number_Drawing.png'

# Make a prediction on personal image
image_array = load_and_preprocess_image(image_path)
prediction = model.predict(image_array)
predicted_class = np.argmax(prediction)

# Visualize of personal image
def visualize_image(image_path, predicted_class):
    img = Image.open(image_path).convert('L')
    plt.imshow(img, cmap='gray')
    plt.title(f"Predicted Class: {predicted_class}")
    plt.axis('off')
    plt.show()

visualize_image(image_path, predicted_class)

